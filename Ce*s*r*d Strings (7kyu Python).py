def uncensor1(infected, discovered):
    result = ""
    j = 0
    for i in infected:
        if i == '*':
            result += discovered[j]
            j+=1
        else:
            result += i
    return result
    
def uncensor2(infected, discovered):
    for i in discovered:
        infected = infected[:infected.find('*')] + i + infected[infected.find('*')+1:]
    return infected
