'''algorithms for local driving (obstacle avoidance) <DWA, Teb local planning, purepersuit, stanly>'''


class DWA_Modified:
    def __init__(self,alpha,beta,gamma,sigma,d) -> None:
        '''
        alpha: param relevant to header function
        beta: param relevant to clearance (obstacle)
        gamma: param relevant to velocity
        omega: distance between global path and now
        '''
        self.a=alpha
        self.b=beta
        self.r=gamma
        self.o=sigma
        self.d=d

        self.Vd=

    

class TEB:
    def __init__(self) -> None:
        pass
                
class PurePersuit:
    def __init__(self) -> None:
        pass

class stanly:
    def __init__(self) -> None:
        pass

    