import random
import time

class Player:
    def __init__(self, name):
        self.name = name

        def welcome_message():
            print("Narrator says :\n-Hello {}, welcome to the game !!".format(self.name))
            print('{} says:\n-'.format(self.name), end='')
        welcome_message()
        self.talk()

    di_view = {}  # for storing the view at each id
    di_path = {}  # for storing available path details from a given id
    di_rev = {}
    state = 'n'   # stores current id
    view_key = ['look', 'see', 'visible', 'view']
    incomplete_key = ['run', 'walk', 'go', 'move', 'back', 'return']
    interesting_responces = ['try next move', 'what to do next ?', 'what next ?', 'still don\'t see any sign of success', 'any further instructions ?']
    negation_statements = ['you can\'t do that !', 'not allowed to do so', 'that won\'t help us to win']
    instructions = []
    instructions_questions = ['instructions', 'play', 'guide']

    with open("instructions.txt", "r") as file:
        instructions = file.read()

    with open("view.txt", "r") as file:
        lines = file.read()
        lines = lines.strip().split(';')
        for line in lines:
            key, val = map(str, line.split(':'))
            di_view[key.strip()] = val.strip()

    with open("path.txt", "r") as file:
        lines = file.read()
        lines = lines.strip().split(';')
        for line in lines:
            key, val = map(str, line.split(':'))
            di_path[key.strip()] = val.strip().split(',')

    with open("rev.txt", "r") as file:
        lines = file.read()
        lines = lines.strip().split(';')
        for line in lines:
            key, val = map(str, line.split(':'))
            di_rev[key.strip()] = val.strip()

    def beautify(self, string, en=0):
        if isinstance(string, str):
            print('Narrator says : \n-', string, sep='')
        if en == 0:
            print(random.choice(self.interesting_responces))
        print('{} says :\n-'.format(self.name), end = '')
        return None

    def process(self, string):
        words = string.strip().split()
        words.reverse()
        for word in words:
                if word in self.incomplete_key:
                    self.beautify("{} in which direction ?".format(word), en =1)
                    return None
                if word in self.di_path[self.state] and word.isalpha():
                    if self.di_rev[word[0][0]] == self.state[-1]:
                        self.state = self.state[:-1]
                    else:
                        self.state += word[0][0]
                    #print(self.state)
                    if self.state == 'nnes':
                        return 1
                    self.beautify('done , what next ?', en=1)
                    return None

                elif word in self.view_key:
                    self.beautify(self.di_view[self.state])
                    return None

                elif word in self.instructions_questions:
                    print('->', self.instructions)
                    print('{} says :\n-'.format(self.name), end='')
                    return None
        self.beautify(random.choice(self.negation_statements)+' , try reading instructions ', en=1)

    def talk(self):
        while True:
            fun = self.process(input())
            if isinstance(fun, int):
                print("congratulations ! You won !")
                time.sleep(3)
                break
            else:
                pass

def main():
    print('Hi user , input your name ^-^ : ')
    p1 = Player(input())

if __name__ == "__main__":
    main()