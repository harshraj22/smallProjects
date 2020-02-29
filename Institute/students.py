from database_handler import DatabaseHandler

class Student:
    def __init__(self, name, password):
        if not self.exists(name):
            raise Exception('No such student exists')
        self.is_student = True

        name = name.strip().lower()
        password = password.strip().lower()
        self.students_list = DatabaseHandler().get_students_list()

        if self.students_list[name]['password'] != password:
            raise Exception('Wrong Credentials')

        self.name = name
        self.password = password

    @staticmethod
    def exists(name):
        students_list = DatabaseHandler().get_students_list()
        name = name.strip().lower()
        if name in students_list.keys():
            return True
        return False

    @staticmethod
    def add_student(**kwargs):
        # check for name and pass
        if not 'name' in kwargs.keys() or not 'password' in kwargs.keys():
            raise Exception('Not enough data to create such Student')
        elif Student.exists(kwargs['name']):
            raise Exception('Student already exists')
        students_list = DatabaseHandler().get_students_list()
        students_list[kwargs['name']]['password'] = kwargs['password']
        DatabaseHandler().update_students_list(students_list)
        
    def update_details(self, **kwargs):
        if 'name' not in kwargs.keys():
            kwargs['name'] = self.name
        if 'password' not in kwargs.keys():
            kwargs['password'] = self.password
        
        del self.students_list[self.name]
        self.students_list[kwargs['name']]['password'] = kwargs['password']
        self.name = kwargs['name']
        self.password = kwargs['password']
        
        DatabaseHandler().update_students_list(self.students_list)

    def give_test(self):
        subjects_list = DatabaseHandler().get_subjects_list()
        correct_answers = int(self.students_list[self.name]['Correct'])
        incorrect_answers = int(self.students_list[self.name]['Incorrect'])
        print(subjects_list)
        subject = input('Enter Subject: ')
        if subject not in subjects_list:
            raise Exception('No Such Subject Plz choose the right one')
        quizes = DatabaseHandler().get_subject_quiz(subject)
        for quiz_name,quiz_data in quizes.items():
            print(quiz_data['Question'])
            for i in range(len(quiz_data['Options'])):
                print(f"{i+1}. {quiz_data['Options'][i]}")
            answer = int(input('Choose your answer: '))
            answer = quiz_data['Options'][answer-1]
            if answer==quiz_data['Answer']:
                print('Correct Answer')
                correct_answers += 1
            else:
                print('Incorrect Answer')
                incorrect_answers += 1

        self.students_list[self.name]['Correct'] = str(correct_answers)
        self.students_list[self.name]['Incorrect'] = str(incorrect_answers)

        DatabaseHandler().update_students_list(self.students_list)

    def show_details(self):
        print(f"\nDetails:\n------------------------------------\nName: {self.name}")
        print(f"Correct Answers: {self.students_list[self.name]['Correct']}")
        print(f"Incorrect Answers: {self.students_list[self.name]['Incorrect']}")