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

    def add_teacher(self, **kwargs):
        # check for name and pass
        if not 'name' in kwargs.keys() or not 'pass' in kwargs.keys():
            raise Exception('Not enough data to create such Teacher')
        elif self.exists(kwargs['name']):
            raise Exception('Teacher already exists')
        teachers_list = DatabaseHandler().get_teachers_list()
        teachers_list[kwargs['name']] = kwargs['pass']
        DatabaseHandler().update_teachers_list(teachers_list)
        
        