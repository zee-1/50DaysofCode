import pandas as pd
import numpy as np
from pprint import pprint
prog_df = pd.read_csv("./Data/Programs.csv")
teacher_df = pd.read_csv("./Data/Teacher.csv")
plannar_df = pd.read_csv("./Data/Plannar.csv")

class Subject:
    def __init__(self,sub_code,sub_name,n_lec,n_tute,n_prac) -> None:
        self.subject_code = sub_code
        self.subject_name = sub_name
        self.n_lec = n_lec
        self.n_tut = n_tute
        self.n_prac= n_prac

class Teacher:
    def __init__(self,name,father_name,department) -> None:
        self.name = name
        self.father_name = father_name
        self.department = department
        self.classes_alloted = []
        self.work_hours_remaining = 16
        self.subject_teaching = []
    def allot_class(self,program):
        self.classes_alloted.append(program)
    def assign_subject(self,sub):
        self.subject_teaching.append(sub)

class Class:
    def __init__(self,program,sem,strength,groups) -> None:
        self.program=program
        self.sem = sem 
        self.strength = strength
        self.groups = groups
        self.alloted_room = None
        self.alloted_teacher = []
        self.subjects = []

    def allot_room(self,room_id):
        self.alloted_room = room_id
        # print("RoomAlloted :",self.allot_room)
    
    def allot_teacher(self,teachers:list):
        self.alloted_teacher = teachers
    def assign_subject(self,sub):
        self.subjects.append(sub)

    def __repr__(self) -> str:
        # print("Program:",self.program)
        # print("Sem:",self.sem)
        # print("Strength:",self.strength)
        return f"\nProgram:{self.program}\nSem: {self.sem}\nStrength: {self.strength}\nGroups:{self.groups}\nRoom Allotedd:{self.alloted_room}"

    
    def __str__(self) -> str:
                return f"\nProgram:{self.program}\nSem: {self.sem}\nStrength: {self.strength}\nGroups:{self.groups}\nRoom Allotedd:{self.alloted_room}"


class Room:
    def __init__(self,room_id,capacity) -> None:
        self.alloted_to = None
        self.room_id = room_id
        self.capacity = capacity
    def allot_to_class(self,class_name):
        self.alloted_to = class_name
    
    def assign_teacher(self,teacher_name):
        self.teacher_name = teacher_name
    def __repr__(self) -> str:
        return f"Room ID:{self.room_id}\nAlloted to class:{self.alloted_to}\nAssigned Teacher:{self.teacher_name}\nCapacity:{self.capacity}"

    def __str__(self) -> str:
        return f"Room ID:{self.room_id}\nAlloted to class:{self.alloted_to}\nAssigned Teacher:{self.teacher_name}\nCapacity:{self.capacity}"

class RoomDF:
    def __init__(self,rooms:list[Room]) -> None:
        self.rooms = rooms
        self.capacity_index = dict()
        self._capacity(self.rooms)

    def _capacity(self,rooms):
        
        for i in (rooms):
            if i.capacity not in self.capacity_index:
                self.capacity_index[i.capacity]=[]
            self.capacity_index[i.capacity].append(i.room_id)
    
    def findByCap(self,cap):
        return self.capacity_index[cap]

    def findById(self,id):
        return self.rooms[id]


def parse_prog_df(prog_df:pd.DataFrame):
    classes_list = []
    for i in range(len(prog_df)):
        strength = prog_df.loc[i,"Strength"]
        if(strength%35==0):
            new_class_strength = int(np.ceil(strength/35))
            # print(f"Diving the program{prog_df.loc[i,'Program']} of  strength {prog_df.loc[i,'Strength']} into {new_class_strength} classes")
            total = strength
            char = 'A'
            for j in range(new_class_strength):
                decided = 35
                groups = (int(np.ceil(decided/35)) if decided>50 else 1)
                obj = Class(f"{prog_df.loc[i,'Program'].strip()}-{prog_df.loc[i,'Sem']}-{char}",prog_df.loc[i,'Sem'],decided,groups=groups)
                classes_list.append(obj)
                total = total-decided
                char = chr(ord(char)+1)
            
        elif(strength%50==0):
            new_class_strength = int(np.ceil(strength/50))
            # print(f"Diving the program{prog_df.loc[i,'Program']} of  strength {prog_df.loc[i,'Strength']} into {new_class_strength} classes")
            total = strength
            char = 'A'
            for j in range(new_class_strength):
                decided = 50
                groups = (int(np.ceil(decided/35)) if decided>50 else 1)
                obj = Class(f"{prog_df.loc[i,'Program'].strip()}-{prog_df.loc[i,'Sem']}-{char}",prog_df.loc[i,'Sem'],decided,groups=groups)
                classes_list.append(obj)
                total = total-decided
                char = chr(ord(char)+1)
        elif(strength%70==0):
            new_class_strength = int(np.ceil(strength/70))
            # print(f"Diving the program{prog_df.loc[i,'Program']} of  strength {prog_df.loc[i,'Strength']} into {new_class_strength} classes")
            total = strength
            char = 'A'
            for j in range(new_class_strength):
                decided = 70
                groups = (int(np.ceil(decided/35)) if decided>50 else 1)
                obj = Class(f"{prog_df.loc[i,'Program'].strip()}-{prog_df.loc[i,'Sem']}-{char}",prog_df.loc[i,'Sem'],decided,groups=groups)
                classes_list.append(obj)
                total = total-decided
                char = chr(ord(char)+1)
        elif(strength>70):
            new_class_strength = int(np.ceil(strength/70))
            # print(f"Diving the program{prog_df.loc[i,'Program']} of  strength {prog_df.loc[i,'Strength']} into {new_class_strength} classes")
            total = strength
            char = 'A'
            for j in range(new_class_strength):
                decided = 70 if (total>70) else total%70
                groups = (int(np.ceil(decided/35)) if decided>50 else 1)
                obj = Class(f"{prog_df.loc[i,'Program'].strip()}-{prog_df.loc[i,'Sem']}-{char}",prog_df.loc[i,'Sem'],decided,groups=groups)
                classes_list.append(obj)
                total = total-decided
                char = chr(ord(char)+1)
        elif(strength<35):
            char = 'A'
            decided = strength
            groups = (int(np.ceil(decided/35)) if decided>50 else 1)
            obj = Class(f"{prog_df.loc[i,'Program'].strip()}-{prog_df.loc[i,'Sem']}-{char}",prog_df.loc[i,'Sem'],decided,groups=groups)
            classes_list.append(obj)
        else:
            print("-->",strength)

    
    return classes_list

def allocate_classes(classes_list:list[Class],rooms=None):
    buck35 = []
    buck70 = []
    buck50 = []

    for i in classes_list:
        if i.strength<= 35:
            buck35.append(i)
        elif i.strength<= 50:
            buck50.append(i)
        elif i.strength<=70:
            buck70.append(i)
    rooms = initRooms()

    #morning half
    rdf = RoomDF(rooms)
    # print(rdf.rooms)
    classes_alloted = set()
    for i in buck35:
        for j in rdf.findByCap(35):
            if rdf.rooms[j-1].alloted_to is None and i.program not in classes_alloted:
                rdf.rooms[j-1].alloted_to = i.program
                i.allot_room(j)
                classes_alloted.add(i.program)
    for i in buck50:
        for j in rdf.findByCap(50):
            if rdf.rooms[j-1].alloted_to is None and i.program not in classes_alloted:
                rdf.rooms[j-1].alloted_to = i.program
                i.allot_room(j)
                classes_alloted.add(i.program)


    for i in buck70:
        for j in rdf.findByCap(70):
            if rdf.rooms[j-1].alloted_to is None and i.program not in classes_alloted:
                rdf.rooms[j-1].alloted_to = i.program
                i.allot_room(j)
                classes_alloted.add(i.program)
    #evening half
    rdf_even = RoomDF(initRooms())
    count=1
    for i in buck35:
        for j in rdf.findByCap(35):
            if rdf_even.rooms[j-1].alloted_to is None and i.program not in classes_alloted:
                rdf_even.rooms[j-1].alloted_to = i.program
                i.allot_room(j)
                classes_alloted.add(i.program)
                count+=1
    for i in buck50:
        for j in rdf_even.findByCap(50):
            if rdf_even.rooms[j-1].alloted_to is None and i.program not in classes_alloted:
                rdf_even.rooms[j-1].alloted_to = i.program
                i.allot_room(j)
                classes_alloted.add(i.program)
                count+=1

    for i in buck70:
        for j in rdf_even.findByCap(70):
            if rdf_even.rooms[j-1].alloted_to is None and i.program not in classes_alloted:
                rdf_even.rooms[j-1].alloted_to = i.program
                i.allot_room(j)
                classes_alloted.add(i.program)
                count+=1
    for i in classes_list:
        if i.program not in classes_alloted:
            print(i.program)
    return classes,rdf,rdf_even

def initRooms():
    rooms = []
    counter = 1
    for i in range(5):
        obj = Room(counter,35)
        counter+=1
        rooms.append(obj)
    for i in range(4):
        obj = Room(counter,70)
        counter+=1
        rooms.append(obj)
    for i in range(1):
        obj = Room(counter,50)
        counter+=1
        rooms.append(obj)
    
    return rooms

def parse_plannar_df(plannar_df:pd.DataFrame):
    plannar = dict();
    for i in range(len(plannar_df)):
        
        if plannar_df.loc[i,'Class'] not in plannar and plannar_df.loc[i,'Class'] is not None:
             plannar[plannar_df.loc[i,'Class']]= []
        plannar[plannar_df.loc[i,'Class']].append((plannar_df.loc[i,'Subject Code'],plannar_df.loc[i,'Subject Name'],plannar_df.loc[i,'L'],plannar_df.loc[i,'T'],plannar_df.loc[i,'P']))

if __name__ == "__main__":
    classes = parse_prog_df(prog_df)
    print("total classes",len(classes))
    classes,morn,even = allocate_classes(classes)