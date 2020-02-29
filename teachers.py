from database_handler import DatabaseHandler

class Teacher:
    def __init__(self, name):
        if not self.exists(name):
            raise Exception('No such teacher exists')
        self.is_teacher = True
    
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
            print(kwargs)
            raise Exception('Not enough data to create such Teacher')
        elif Teacher.exists(kwargs['name']):
            raise Exception('Teacher already exists')
        teachers_list = DatabaseHandler().get_teachers_list()
        teachers_list[kwargs['name']] = kwargs['password']
        DatabaseHandler().update_teachers_list(teachers_list)
        
