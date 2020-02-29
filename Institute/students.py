from database_handler import DatabaseHandler

class Student:
    def __init__(self, name, password):
        if not self.exists(name):
            raise Exception('No such student exists')
        self.is_student = True

        name = name.strip().lower()
        password = password.strip().lower()
        self.students_list = DatabaseHandler().get_students_list()

        if self.students_list[name] != password:
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
        students_list[kwargs['name']] = kwargs['password']
        DatabaseHandler().update_students_list(students_list)
        
    def update_details(self, **kwargs):
        if 'name' not in kwargs.keys():
            kwargs['name'] = self.name
        if 'password' not in kwargs.keys():
            kwargs['password'] = self.password
        
        del self.students_list[self.name]
        self.students_list[kwargs['name']] = kwargs['password']
        self.name = kwargs['name']
        self.password = kwargs['password']
        
        DatabaseHandler().update_students_list(self.students_list)

