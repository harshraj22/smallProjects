from database_handler import DatabaseHandler

class Student:
    def __init__(self):
        pass

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
        
