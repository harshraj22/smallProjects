from database_handler import DatabaseHandler

class Teacher:
    def __init__(self):
        pass
    
    def exists(self, name):
        teachers_list = DatabaseHandler().get_teachers_list()
        name = name.strip().lower()
        if name in teachers_list.keys():
            return True
        return False