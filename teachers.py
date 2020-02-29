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

        for subject in all_tests:
            for name, test_data in subject.items():
                if test_data['author'] == self.name:
                    my_tests[name] = test_data
        return my_tests
