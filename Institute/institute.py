import argparse
from getpass import getpass
from teachers import Teacher
from students import Student

class User():
    def __init__(self, name, password):
        try:
            # if credentials are for student
            user = Student(name, password)
            user.interact()
        # throw better exeptions and catch specific exeptions
        except Exception as e:
            user = Teacher(name, password)
            user.interact()
        except:
            raise Exception('Designation unknown')

    @staticmethod
    def create_user(name, password, designation):
        '''
            creates user (student/teacher) with given credentials
        '''
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

    # if user chose to login
    if args.login:
        user = User(name=args.name, password=args.password)
    elif args.signUp:
        User.create_user(name=args.name, password=args.password, designation=args.type)

if __name__=='__main__':
    main()