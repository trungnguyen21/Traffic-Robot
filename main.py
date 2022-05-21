from cgitb import grey
from tkinter import *
from tkinter import messagebox
import cv2
import PIL.Image, PIL.ImageTk
import time
import sys

sys.path.append('D:\Python_Projects\Real-time Camera\camera\Lib\site-packages')


# widgets with canvas and camera
class tkCamera1(Frame):

    def __init__(self, window, video_source=0):
        super().__init__(window)
        
        self.window = window

        Label(self.window, text='CAMERA 2', bg='grey').place(y = 70, x=200)
        self.video_source = video_source
        self.vid = MyVideoCapture(self.video_source)

        self.canvas = Canvas(window, width=self.vid.width, height=self.vid.height)
        self.canvas.place(width=400, y=100, x = 30)
         
        # After it is called once, the update method will be automatically called every delay milliseconds
        self.delay = 15
        self.update_widget()

    def snapshot(self):
        # Get a frame from the video source
        ret, frame = self.vid.get_frame()
        
        if ret:
            cv2.imwrite("frame-" + time.strftime("%d-%m-%Y-%H-%M-%S") + ".jpg", cv2.cvtColor(frame, cv2.COLOR_RGB2BGR))
    
    def update_widget(self):
        # Get a frame from the video source
        ret, frame = self.vid.get_frame()
        
        if ret:
            self.image = PIL.Image.fromarray(frame)
            self.photo = PIL.ImageTk.PhotoImage(image=self.image)
            self.canvas.create_image(0, 0, image = self.photo, anchor = NW)
        
        self.window.after(self.delay, self.update_widget)


class tkCamera2(Frame):

    def __init__(self, window, video_source=0):
        super().__init__(window)
        
        self.window = window
        
        Label(self.window, text='CAMERA 1', bg='grey').place(y = 70, x=600)
        self.video_source = video_source
        self.vid = MyVideoCapture(self.video_source)

        self.canvas = Canvas(window, width=self.vid.width, height=self.vid.height)
        self.canvas.place(width = 400, y=100, x = 425)
         
        # After it is called once, the update method will be automatically called every delay milliseconds
        self.delay = 15
        self.update_widget()

    def snapshot(self):
        # Get a frame from the video source
        ret, frame = self.vid.get_frame()
        
        if ret:
            cv2.imwrite("frame-" + time.strftime("%d-%m-%Y-%H-%M-%S") + ".jpg", cv2.cvtColor(frame, cv2.COLOR_RGB2BGR))
    
    def update_widget(self):
        # Get a frame from the video source
        ret, frame = self.vid.get_frame()
        
        if ret:
            self.image = PIL.Image.fromarray(frame)
            self.photo = PIL.ImageTk.PhotoImage(image=self.image)
            self.canvas.create_image(0, 0, image = self.photo, anchor = NW)
        
        self.window.after(self.delay, self.update_widget)


class App:
        
    # Create a canvas that can fit the above video source size
    def __init__(self, window, window_title):

        # Create a function to gather input then start the cameras
        def startcam1():        
            # open video source (by default this will try to open the computer webcam)
            try:
                video_source1 = f'rtsp://livecam:alpine@{ip_address_1.get()}:554/stream1'
                # video_source1 = "./Gojo.mp4"
                self.vid1 = tkCamera1(window, video_source1)
                self.vid1.place()
            except ValueError:
                '''DISPLAY AN ERROR FOR USER'''
                messagebox.showerror("Error for Camera 1", "Invalid IP Address/ Camera not found")
                # Label(self.window, text="Invalid IP Address!").place(x= 30, y = 50)
                return
            
        def startcam2():
            # Default will attempt to open the webcam
            try: 
                video_source2 = f'rtsp://livecam:alpine@{ip_address_2.get()}:554/stream1' 
                self.vid2 = tkCamera2(window, video_source2)
                self.vid2.place()
            except ValueError:
                messagebox.showerror("Error for Camera 2", "Invalid IP Address/ Camera not found")
                # Label(self.window, text="Invalid IP Address!").place(x= 30, y = 50)
                return
            
           

        # Create window
        self.window = window
        self.window.title(window_title)

        # Layout for the entry section
        Label(window, text = "IP Address for Cam 1: ").grid(row=0, column=0, sticky=W, pady = 4, padx=5)
        Label(window, text = "IP Address for Cam 2: ").grid(row=0, column=3, sticky=W, pady = 4, padx=5)

        ip_address_1 = Entry(window)
        ip_address_2 = Entry(window)

        ip_address_1.grid(row=0, column=1, sticky=W, pady = 4, padx=2)
        ip_address_2.grid(row=0, column=4, sticky=W, pady = 4, padx=2)

        # Start Button to init the camera
        Button(
            window,
            text="Start Camera 1",
            command = startcam1
        ).grid(row=0, column=2, sticky=W, pady = 4, padx=10)

        Button(
            window,
            text="Start Camera 2",
            command = startcam2
        ).grid(row=0, column=5, sticky=W, pady = 4, padx=10)

        self.window.mainloop()
        
         
        
     
class MyVideoCapture:
    def __init__(self, video_source=0):
        # Open the video source
        self.vid = cv2.VideoCapture(video_source)
        if not self.vid.isOpened():
            raise ValueError("Unable to open video source", video_source)
            
    
        # Get video source width and height
        self.width = self.vid.get(cv2.CAP_PROP_FRAME_WIDTH)
        self.height = self.vid.get(cv2.CAP_PROP_FRAME_HEIGHT)
    
        self.width = 400
        self.height = 300
    
    def get_frame(self):
        if self.vid.isOpened():
            ret, frame = self.vid.read()
            if ret:
                frame = cv2.resize(frame, (400, 300))
                # Return a boolean success flag and the current frame converted to BGR
                return (ret, cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
            else:
                return (ret, None)
        else:
            return (ret, None)
    
    # Release the video source when the object is destroyed
    def __del__(self):
        if self.vid.isOpened():
            self.vid.release()
 
# Create a window and pass it to the Application object
window = Tk()
window.geometry("854x480")
App(window, "Realtime Duo Camera - Traffic Robot")


