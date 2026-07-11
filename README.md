# Salary Management System

A Flask-based salary management application with:
- user registration and login
- salary record storage and editing
- help desk support requests
- dashboard view for tracking payroll records

## Run locally

1. Create a virtual environment
   ```bash
   python -m venv .venv
   .venv\Scripts\activate
   ```
2. Install dependencies
   ```bash
   pip install -r requirements.txt
   ```
3. Start the app
   ```bash
   python app.py
   ```
4. Open your browser at
   ```text
   http://127.0.0.1:5000
   ```

## Run tests

```bash
python -m unittest discover -s tests -v
```

## Deploy to GitHub

1. Initialize Git
   ```bash
   git init
   git add .
   git commit -m "Initial commit"
   ```
2. Create a repository on GitHub.
3. Connect the remote
   ```bash
   git remote add origin https://github.com/your-username/your-repo-name.git
   git branch -M main
   git push -u origin main
   ```

## Deploy to Render or Heroku

### Render
1. Create a new Web Service on Render.
2. Connect this repository.
3. Set the build command to `pip install -r requirements.txt`.
4. Set the start command to `python app.py`.

### Heroku
```bash
heroku create
heroku git:remote -a your-heroku-app-name
git push heroku main
```

## Notes

- Set a secret key in production:
  ```bash
  export SECRET_KEY=your-secret-key
  ```
