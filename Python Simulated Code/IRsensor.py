import random

#float LeftIRsensorInput
#float CenterIRsensorInput
#float RightIRsensorInput
IR = [0,0,0] #[left, center, right] output return

def IRsensorCollect():
    LeftIRsensorInput = random.random()
    CenterIRsensorInput = random.random()
    RightIRsensorInput = random.random()

    print LeftIRsensorInput
    print CenterIRsensorInput
    print RightIRsensorInput

    IR[0] = LeftIRsensorInput
    IR[1] = CenterIRsensorInput
    IR[2] = RightIRsensorInput
    return IR


#IRsensorCollect()
