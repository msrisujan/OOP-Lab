from tkinter import *

if __name__=="__main__":
    top=Tk()

    top.configure(background="cyan")

    top.title("BMI Calculator")

    h_val=StringVar()
    w_val=StringVar()
    bmi_val=StringVar()

    height_label=Label(top,text="Height(in meters)",background="cyan")
    height_label.grid(row=0,column=0)

    height_entry=Entry(top,textvariable=h_val, highlightthickness=2)
    height_entry.grid(row=0,column=1)

    weight_label=Label(top,text="Weight(in Kgs)",background="cyan")
    weight_label.grid(row=1,column=0)

    weight_entry=Entry(top,textvariable=w_val,highlightthickness=2)
    weight_entry.grid(row=1,column=1)

    bmi_label=Label(top,text="Your BMI",background="cyan")
    bmi_label.grid(row=2,column=0)

    bmi_entry=Entry(top,textvariable=bmi_val,highlightthickness=2)
    bmi_entry.grid(row=2,column=1)

    def calculate_bmi():
        h1=h_val.get()
        w1=w_val.get()
        h2=""
        w2=""
        for i in range(len(h1)):
            if h1[i]!='.':
                h2 += h1[i]
        
        for i in range(len(w1)):
            if w1[i]!='.':
                w2 += w1[i]

        if len(h_val.get())==0 or len(w_val.get())==0:
            bmi="Please give Input"
            bmi_val.set(bmi)

        elif h2.isnumeric()==False or w2.isnumeric()==False:
            bmi="Invalid Input"
            bmi_val.set(bmi)

        elif(float(h_val.get())<=0 or float(w_val.get())<=0):
            bmi="Invalid Input"
            bmi_val.set(bmi)

        else :
            h=float(h_val.get())
            w=float(w_val.get())
            bmi=round(w/(h*h),2)

            bmi_val.set(bmi)

    cal_button=Button(top,text="Calculate",bg="lightgreen",command=calculate_bmi)
    cal_button.grid(row=3,column=1)
            
    top.mainloop()
    
