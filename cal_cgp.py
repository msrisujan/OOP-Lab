from tkinter import *
top=Tk()

top.configure(background="cyan")

top.title("MARKSHEET")



name_l=Label(top,text="Name",background="cyan")
name_l.grid(row=0,column=0)

name_e=Entry(top)
name_e.grid(row=0,column=1)

roll_l=Label(top,text="Roll.No",background="cyan")
roll_l.grid(row=1,column=0)

roll_e=Entry(top)
roll_e.grid(row=1,column=1)

serial_l=Label(top,text="Srl.No",background="cyan")
serial_l.grid(row=2,column=0)
serial1_l=Label(top,text="1",background="cyan")
serial1_l.grid(row=3,column=0)
serial2_l=Label(top,text="2",background="cyan")
serial2_l.grid(row=4,column=0)
serial3_l=Label(top,text="3",background="cyan")
serial3_l.grid(row=5,column=0)
serial4_l=Label(top,text="4",background="cyan")
serial4_l.grid(row=6,column=0)

sub_l=Label(top,text="Subject",background="cyan")
sub_l.grid(row=2,column=1)
sub_e=Label(top,text="Grade",background="cyan")
sub_e.grid(row=2,column=2)

sub1_l=Label(top,text="CS 201",background="cyan")
sub1_l.grid(row=3,column=1)
sub1_e=Entry(top)
sub1_e.grid(row=3,column=2)

sub2_l=Label(top,text="CS 202",background="cyan")
sub2_l.grid(row=4,column=1)
sub2_e=Entry(top)
sub2_e.grid(row=4,column=2)

sub3_l=Label(top,text="MA 201",background="cyan")
sub3_l.grid(row=5,column=1)
sub3_e=Entry(top)
sub3_e.grid(row=5,column=2)

sub4_l=Label(top,text="EC 201",background="cyan")
sub4_l.grid(row=6,column=1)
sub4_e=Entry(top)
sub4_e.grid(row=6,column=2)


subc_l=Label(top,text="Sub Credit",background="cyan")
subc_l.grid(row=2,column=3)
subc1_l=Label(top,text="4",background="cyan")
subc1_l.grid(row=3,column=3)
subc2_l=Label(top,text="4",background="cyan")
subc2_l.grid(row=4,column=3)
subc3_l=Label(top,text="3",background="cyan")
subc3_l.grid(row=5,column=3)
subc4_l=Label(top,text="4",background="cyan")
subc4_l.grid(row=6,column=3)
subc5_l=Label(top,text="Total credit",background="cyan")
subc5_l.grid(row=7,column=3)
subc6_l=Label(top,text="SGPA",background="cyan")
subc6_l.grid(row=8,column=3)

reg_l=Label(top,text="Reg.No",background="cyan")
reg_l.grid(row=0,column=3)
reg_e=Entry(top)
reg_e.grid(row=0,column=4)

credit_l=Label(top,text="Credit obtained",background="cyan")
credit_l.grid(row=2,column=4)
credit1_l=Label(top,text="",background="cyan")
credit1_l.grid(row=3,column=4)
credit2_l=Label(top,text="",background="cyan")
credit2_l.grid(row=4,column=4)
credit3_l=Label(top,text="",background="cyan")
credit3_l.grid(row=5,column=4)
credit4_l=Label(top,text="",background="cyan")
credit4_l.grid(row=6,column=4)

totalc_l=Label(top,text="",background="cyan")
totalc_l.grid(row=7,column=4)

gpa_l=Label(top,text="",background="cyan")
gpa_l.grid(row=8,column=4)


grades = {"S": 10, "A": 9,"B": 8,"C": 7,"D": 6,"E": 5,"U": 0,"I": 0,"W": 0}

def calculate_gpa():
    g1=grades.get(sub1_e.get(), -1)
    g2=grades.get(sub2_e.get(), -1)
    g3=grades.get(sub3_e.get(), -1)
    g4=grades.get(sub4_e.get(), -1)
    if(len(name_e.get())==0):
        gpa="Please Enter Name"
        credit1_l.configure(text="")
        credit2_l.configure(text="")
        credit3_l.configure(text="")
        credit4_l.configure(text="")
        gpa_l.configure(text=gpa,fg="red")
    elif(len(roll_e.get())==0):
        gpa="Please Enter Roll.No"
        credit1_l.configure(text="")
        credit2_l.configure(text="")
        credit3_l.configure(text="")
        credit4_l.configure(text="")
        gpa_l.configure(text=gpa,fg="red")
    elif(len(reg_e.get())==0):
        gpa="Please Enter Reg.No"
        credit1_l.configure(text="")
        credit2_l.configure(text="")
        credit3_l.configure(text="")
        credit4_l.configure(text="")
        gpa_l.configure(text=gpa,fg="red")
    elif(g1==-1 or g2==-1 or g3==-1 or g4==-1):
        gpa="Please Give Correct Input"
        credit1_l.configure(text="")
        credit2_l.configure(text="")
        credit3_l.configure(text="")
        credit4_l.configure(text="")
        gpa_l.configure(text=gpa,fg="red")

    else:
        c1=g1*4
        c2=g2*4
        c3=g3*4
        c4=g4*4
        credit1_l.configure(text=c1,fg="red")
        credit2_l.configure(text=c2,fg="red")
        credit3_l.configure(text=c3,fg="red")
        credit4_l.configure(text=c4,fg="red")
        tc=c1+c2+c3+c4
        totalc_l.configure(text=tc,fg="green")
        gpa=round(tc/15,2)
        gpa_l.configure(text=gpa,fg="green")
    
submit_b=Button(top,text="Submit",background="lightgreen",command=calculate_gpa)
submit_b.grid(row=8,column=1)

top.mainloop()