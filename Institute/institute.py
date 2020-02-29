import argparse
from getpass import getpass
from teachers import Teacher
from students import Student

class User(Teacher, Student):
    def __init__(self, name, password):
        pass

    @staticmethod
    def create_user(name, password, designation):
        if designation == 'student':
            Student.add_student(name=name, password=password)
        elif designation == 'teacher':
            Teacher.add_teacher(name=name, password=password)
        else:
            raise Exception('Wrong designation type')

def main():
    parser = argparse.ArgumentParser(description='Command line interface to interact with institute records for teachers and students')

    parser.add_argument('-n', '--name', help='user name', required=True)
    parser.add_argument('-p', '--password', help='user password', required=True)

    parser.add_argument('-t', '--type', choices=['student', 'teacher'], help='choose if you are a teacher or student', required=True )

    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--login', help='login using credentials', action='store_true')
    group.add_argument('--signUp', help='create user for institution', action='store_true')

    args = parser.parse_args()

    if args.login:
        pass
    elif args.signUp:
        User.create_user(name=args.name, password=args.password, designation=args.type)

    print(f'input data : name={args.name}, and password={args.password}')

if __name__=='__main__':
    main()