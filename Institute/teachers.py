from database_handler import DatabaseHandler

class Teacher:
    def __init__(self, name, password):
        if not self.exists(name):
            raise Exception('No such teacher exists')
        self.is_teacher = True
        
        name = name.strip().lower()
        password = password.strip().lower()
        self.teachers_list = DatabaseHandler().get_teachers_list()

        if self.teachers_list[name] != password:
            raise Exception('Wrong Credentials')

        self.name = name
        self.password = password

    def interact(self):
        options = {'A':'Add Problems', 'B':'Update Details', 'C':'List Problems by me'}
        for key, value in options.items():
            print('\t', key, value)
        
        choise = input()

        if choise == 'A':
            self.add_problems()
        elif choise == 'B':
            name = input('Enter user name')
            password = input('Enter user password')
            self.update_details(name=name, password=password)
        elif choise == 'C':
            print(self.tests_by_me())
        else:
            self.interact()
    
    @staticmethod
    def exists(name):
        teachers_list = DatabaseHandler().get_teachers_list()
        name = name.strip().lower()
        if name in teachers_list.keys():
            return True
        return False

    @staticmethod
    def add_teacher(**kwargs):
        # check for name and pass
        if not 'name' in kwargs.keys() or not 'password' in kwargs.keys():
            raise Exception('Not enough data to create such Teacher')
        elif Teacher.exists(kwargs['name']):
            raise Exception('Teacher already exists')
        teachers_list = DatabaseHandler().get_teachers_list()
        teachers_list[kwargs['name']] = kwargs['password']
        DatabaseHandler().update_teachers_list(teachers_list)

    def update_details(self, **kwargs):
        if 'name' not in kwargs.keys():
            kwargs['name'] = self.name
        if 'password' not in kwargs.keys():
            kwargs['password'] = self.password
        
        del self.teachers_list[self.name]
        self.teachers_list[kwargs['name']] = kwargs['password']
        self.name = kwargs['name']
        self.password = kwargs['password']
        
        DatabaseHandler().update_teachers_list(self.teachers_list)
        
    def tests_by_me(self):
        # add tests to check this method
        all_tests = DatabaseHandler().get_tests_list()
        my_tests = dict()

        for subject_name, subject_data in all_tests.items():
            for name, test_data in subject_data.items():
                if test_data['author'] == self.name:
                    my_tests[name] = test_data
        return my_tests

    def add_problems(self):
        quizzes_list = DatabaseHandler().get_tests_list()

        subject_name = input("Enter Subject Name: ").strip()
        quiz_name = input("Enter Quiz name: ").strip()
        question = input("Enter question: ").strip()
        options = []
        for i in range(4):
            temp = input(f"Enter option {i}: ").strip()
            options.append(temp)
        answer = input('Enter answer for the question : ')
        
        if subject_name not in quizzes_list.keys():
            print('No Such Subject Exists')
            # raise Exception('No such subject found')

        new_quiz_data = {
            "author": self.name,
            "Question": question,
            "Options": options,
            "Answer":answer
        }

        if subject_name not in quizzes_list:
            quizzes_list[subject_name] = dict()
        
        quizzes_list[subject_name][quiz_name] = new_quiz_data
        DatabaseHandler().add_new_quiz(quizzes_list)
