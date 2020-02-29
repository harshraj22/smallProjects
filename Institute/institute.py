import argparse
from getpass import getpass
from teachers import Teacher
from students import Student

class User(Teacher, Student):
    pass

def main():
    parser = argparse.ArgumentParser(description='Command line interface to interact with institute records for teachers and students')

    parser.add_argument('-n', '--name', help='user name', required=True)
    parser.add_argument('-p', '--password', help='user password', required=True)

    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--login', help='login using credentials', action='store_true')
    group.add_argument('--signUp', help='create user for institution', action='store_true')

    args = parser.parse_args()

    if args.login:
        pass
    elif args.signUp:
        pass

    print(f'input data : name={args.name}, and password={args.password}')

if __name__=='__main__':
    main()