from database_handler import DatabaseHandler

class Student:
    def __init__(self):
        pass

    def exists(self, name):
        students_list = DatabaseHandler().get_students_list()
        name = name.strip().lower()
        if name in students_list.keys():
            return True
        return False

    def exists(self, name):
        students_list = DatabaseHandler().get_students_list()
        name = name.strip().lower()
        if name in students_list.keys():
            return True
        return False

    def add_student(self, **kwargs):
        # check for name and pass
        if not 'name' in kwargs.keys() or not 'pass' in kwargs.keys():
            raise Exception('Not enough data to create such Teacher')
        elif self.exists(kwargs['name']):
            raise Exception('Teacher already exists')
        students_list = DatabaseHandler().get_students_list()
        students_list[kwargs['name']] = kwargs['pass']
        DatabaseHandler().update_students_list(students_list)