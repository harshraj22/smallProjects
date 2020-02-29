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