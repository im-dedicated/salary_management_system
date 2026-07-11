import os
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from app import app, init_db


class SalaryManagementSystemTestCase(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory()
        self.db_path = os.path.join(self.temp_dir.name, "test_salary.db")
        app.config.update(TESTING=True, DATABASE=self.db_path)
        self.client = app.test_client()
        with app.app_context():
            init_db()

    def tearDown(self):
        self.temp_dir.cleanup()

    def test_index_page(self):
        response = self.client.get("/")
        self.assertEqual(response.status_code, 200)
        self.assertIn(b"Salary Management System", response.data)

    def test_registration_and_login_flow(self):
        register_response = self.client.post(
            "/register",
            data={
                "username": "demo",
                "email": "demo@example.com",
                "password": "secret123",
                "confirm_password": "secret123",
            },
            follow_redirects=True,
        )
        self.assertEqual(register_response.status_code, 200)

        login_response = self.client.post(
            "/login",
            data={"username": "demo", "password": "secret123"},
            follow_redirects=True,
        )
        self.assertEqual(login_response.status_code, 200)
        self.assertIn(b"Welcome back!", login_response.data)

    def test_salary_can_be_added_and_edited(self):
        self.client.post(
            "/register",
            data={
                "username": "payroll",
                "email": "payroll@example.com",
                "password": "secret123",
                "confirm_password": "secret123",
            },
            follow_redirects=True,
        )
        self.client.post(
            "/login",
            data={"username": "payroll", "password": "secret123"},
            follow_redirects=True,
        )

        self.client.post(
            "/salaries",
            data={
                "employee_name": "Jane Doe",
                "position": "Developer",
                "department": "Engineering",
                "salary": "5500",
                "bonus": "500",
                "status": "Paid",
            },
            follow_redirects=True,
        )

        edit_response = self.client.post(
            "/salaries/1/edit",
            data={
                "employee_name": "Jane Smith",
                "position": "Senior Developer",
                "department": "Platform",
                "salary": "6000",
                "bonus": "700",
                "status": "Pending",
            },
            follow_redirects=True,
        )

        self.assertEqual(edit_response.status_code, 200)
        self.assertIn(b"Jane Smith", edit_response.data)
        self.assertIn(b"6000", edit_response.data)


if __name__ == "__main__":
    unittest.main()
