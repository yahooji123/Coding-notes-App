# Coding Notes Documentary Website

This is a Node.js website to manage and display your coding notes.

## Setup

1.  Navigate to the `website` folder:
    ```
    cd website
    ```

2.  Install dependencies:
    ```
    npm install
    ```

3.  Ensure MongoDB is running locally. If you don't have MongoDB installed, please install it or update the `MONGO_URI` in `.env` to a cloud database (like MongoDB Atlas).

4.  Start the server:
    ```
    npm start
    ```
    Or for development with auto-restart:
    ```
    npm run dev
    ```

5.  Open your browser to `http://localhost:5000`.

## Admin Workflow

1.  **First Registration**: The first user to register at `/register` will automatically become the **Super Admin**.
2.  **Login**: Log in with your new credentials at `/login`.
3.  **Dashboard**:Go to `/dashboard`.
    - You will see a "Super Admin Controls" section.
    - You can **Enable** or **Disable** registration for others.
    - By default, registration is **Enabled**. You should disable it after you register if you don't want strangers to sign up.
4.  **Adding Admins**: To add another admin (`User 2`), enable registration, ask them to register, then disable registration again. They will be a regular Admin (cannot toggle registration).
5.  **Adding Notes**: Use the "+ Add New Note" button to add documentary notes. You can paste your code or text there.
