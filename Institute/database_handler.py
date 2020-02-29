import json

INSTITUTION_TEMPLATE = '''
	{
		"Institution":{
			"Students":{
	
			}, 	
			"Teachers":{
			
			},
			"Quizzes":{
				"DataStructures":{

				},
				"Algorithms":{

				},
				"MachineLearning":{

				}
			}
		}
	}
'''


class DatabaseHandler:
    def __init__(self):
        # add a try catch block if the file does not exists
        with open('database.json') as f:
            self.institute_data = json.load(f)

    def get_students_list(self):
        return self.institute_data['Institution']['Students']

    def get_teachers_list(self):
        return self.institute_data['Institution']['Teachers']

    def update_teachers_list(self, teachers_list):
        # make some check to be sure teachers_list is in same format as required
        self.institute_data['Institution']['Teachers'] = teachers_list
        with open('database.json', 'w') as f:
            json.dump(self.institute_data, f, indent=2)
    
    def update_students_list(self, students_list):
        # make some check to be sure students_list is in same format as required
        self.institute_data['Institution']['Students'] = students_list
        with open('database.json', 'w') as f:
            json.dump(self.institute_data, f, indent=2)

    def get_subjects_list(self):
    	'''
    		returns list of subjects available to give quiz
    	'''
    	Quizzes_dict =  self.institute_data['Institution']['Quizzes']
    	subjects_lists = list(Quizzes_dict.keys())
    	return subjects_lists
    def get_subject_quiz(self,subject):
    	'''
    		returns a list of quizzes in respective subject
    	'''
    	return self.institute_data['Institution']['Quizzes'][subject]

    def get_tests_list(self):
    	''' returning a quizess dictionary  by that author who is logged in it returns
    	 name of subject name as key and in subject name key as quiz name'''
    	return self.institute_data['Institution']['Quizzes']

    def add_new_quiz(self, quizzes_list):
        # make some check to be sure quizzes_list is in same format as required
        self.institute_data['Institution']['Quizzes'] = quizzes_list
        with open('database.json', 'w') as f:
            json.dump(self.institute_data, f, indent=2)

