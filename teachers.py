from database_handler import DatabaseHandler

class Teacher:
    def __init__(self, name):
        if not self.exists(name):
            raise Exception('No such teacher exists')
        self.is_teacher = True
    
    def exists(self, name):
        teachers_list = DatabaseHandler().get_teachers_list()
        name = name.strip().lower()
        if name in teachers_list.keys():
            return True
        return False