import numpy as np
def maxRoom(roomCount):
    maxVal=-1
    maxIdx = -1
    for k,v in roomCount.items():
        if v>maxVal:
            maxVal = v
            maxIdx = k
    return maxIdx,maxVal
def roomAssigner(classStrength:list,roomCap:np.array):
    classStrength.sort()
    roomCap.sort()
    roomAv = dict()
    for i in range(len(roomCap)):
        roomAv[i]=False
    roomCount = dict()
    for i in range(len(roomCap)):
        if roomCap[i] not in roomCount:
            roomCount[roomCap[i]]=0
        roomCount[roomCap[i]]+=1
    
    for i in range(len(roomCap)):
        roomToUse = roomCap[i]
        if(not roomAv[i]):
            selectedClass = None
            print("Looking for :",roomToUse)
            for j in range(len(classStrength)):
                if classStrength[j]<=roomToUse:
                    selectedClass = classStrength[j]
            if selectedClass is None:
                continue
            print(selectedClass," for room with strenght ",roomToUse)
            roomAv[i]=True
            classStrength.remove(selectedClass)

def divClasses(classStren):
    for i in range(len(classStren)):
        if classStren[i]%50==0:
            print("Dividing with 50",classStren[i])
        elif classStren[i]%35==0:
            print("Dividing with 35",classStren[i])
        elif classStren[i]%70==0:
            print("Dividing with 70",classStren[i])


if __name__ =='__main__':
    classStren = ([130,130,70,130,130,100,18,18,25,25])
    roomCap =([50,35,35,35,35,35,70,70,70,70])
    # selectedClassroom = np.unique(roomCap,return_counts=True)
    # a = np.where(selectedClassroom[1]==selectedClassroom[1].max())
    # print(selectedClassroom[0][a])
    # print(roomCap[np.where(roomCap == selectedClassroom[0][a])][0])
    # print(selectedClassroom)
    # roomAssigner(classStren,roomCap)
    divClasses(classStren)