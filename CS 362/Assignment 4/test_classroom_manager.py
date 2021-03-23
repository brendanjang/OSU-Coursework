from classroom_manager import *

import unittest

'''
ClassroomManager Unit Tests
'''
class TestClassroomManager(unittest.TestCase):

    # Test Student constructor
    def test_student_constructor(self):
        student = Student(123, "Sara", "Smith")
        self.assertEqual(123, student.id)
        self.assertEqual("Sara", student.first_name)
        self.assertEqual("Smith", student.last_name)
        self.assertEqual([], student.assignments)

    # Test Student get_full_name method
    def test_student_get_full_name(self):
        student = Student(123, "Sara", "Smith")
        self.assertEqual("Sara Smith", student.get_full_name())

    # Test Student submit_assignment method
    def test_student_submit_assignment(self):
        student = Student(123, "Sara", "Smith")
        assignment = Assignment("Assignment 1", 68)
        student.submit_assignment(assignment)
        self.assertEqual([assignment], student.assignments)

    # Test Student get_assignments method
    def test_student_get_assignments(self):
        student = Student(123, "Sara", "Smith")
        assignment1 = Assignment("Assignment 1", 68)
        student.submit_assignment(assignment1)
        assignment2 = Assignment("Assignment 2", 72)
        student.submit_assignment(assignment2)
        self.assertEqual([assignment1, assignment2], student.get_assignments())

    # Test Student get_assignment(name) method
    def test_student_get_assignment_name(self):
        student = Student(123, "Sara", "Smith")
        assignment1 = Assignment("Assignment 1", 68)
        student.submit_assignment(assignment1)
        assignment2 = Assignment("Assignment 2", 72)
        student.submit_assignment(assignment2)
        self.assertEqual(assignment1, student.get_assignment("Assignment 1"))
        self.assertEqual(assignment2, student.get_assignment("Assignment 2"))
        self.assertEqual(None, student.get_assignment("Assignment 3"))

    # Test Student get_average method
    def test_student_get_average(self):
        student = Student(123, "Sara", "Smith")
        assignment1 = Assignment("Assignment 1", 68)
        assignment1.grade = 60
        student.submit_assignment(assignment1)
        assignment2 = Assignment("Assignment 2", 72)
        assignment2.grade = 65
        student.submit_assignment(assignment2)
        self.assertEqual(62.5, student.get_average())
        assignment3 = Assignment("Assignment 3", 50)
        assignment3.grade = None
        student.submit_assignment(assignment3)
        self.assertEqual(62.5, student.get_average())

    # Test Student remove_assignment method
    def test_student_remove_assignment(self):
        student = Student(123, "Sara", "Smith")
        assignment1 = Assignment("Assignment 1", 68)
        student.submit_assignment(assignment1)
        assignment2 = Assignment("Assignment 2", 72)
        student.submit_assignment(assignment2)
        self.assertEqual([assignment1, assignment2], student.get_assignments())
        student.remove_assignment("Assignment 1")
        self.assertEqual([assignment2], student.get_assignments())
        student.remove_assignment("Assignment 3")
        self.assertEqual([assignment2], student.get_assignments())
        student.remove_assignment("Assignment 2")
        self.assertEqual([], student.get_assignments())

    # Test Assignment constructor
    def test_assignment_constructor(self):
        assignment = Assignment("Assignment 1", 68)
        self.assertEqual("Assignment 1", assignment.name)
        self.assertEqual(68, assignment.max_score)
        self.assertEqual(None, assignment.grade)

    # Test Assignment assign_grade method
    def test_assignment_assign_grade(self):
        assignment = Assignment("Assignment 1", 68)
        self.assertEqual(None, assignment.grade)
        assignment.assign_grade(59)
        self.assertEqual(59, assignment.grade)
        assignment.assign_grade(69)
        self.assertEqual(None, assignment.grade)

# Run Unit Tests on execution
if __name__ == '__main__':
    unittest.main()
