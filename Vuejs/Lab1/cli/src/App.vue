<template>
  <div class="container">
    <header>
      <h1>Open Source Mansoura</h1>
    </header>

    <div class="content">
      <nav class="sidebar">
        <ul>
          <li><a href="#" :class="{ active: activeTab === 'home' }" @click="activeTab = 'home'">Home</a></li>
          <li><a href="#" :class="{ active: activeTab === 'contact' }" @click="activeTab = 'contact'">Contact</a></li>
          <li><a href="#" :class="{ active: activeTab === 'about' }" @click="activeTab = 'about'">About</a></li>
          <li><a href="#" :class="{ active: activeTab === 'gallery' }" @click="activeTab = 'gallery'">Gallery</a></li>
        </ul>
      </nav>

      <main class="main-content">
        <div class="table-container">
          <div class="table-header">
            <button class="btn-add" @click="openModal">Add</button>
          </div>

          <table class="students-table">
            <thead>
              <tr>
                <th>ID</th>
                <th>Name</th>
                <th>City</th>
                <th>Actions</th>
              </tr>
            </thead>
            <tbody>
              <tr v-for="student in students" :key="student.id">
                <td>{{ student.id }}</td>
                <td>{{ student.name }}</td>
                <td>{{ student.city }}</td>
                <td>
                  <button class="btn-toggle" @click="toggleDetails(student)">toggler</button>
                </td>
              </tr>
            </tbody>
            <tfoot>
              <tr>
                <td colspan="4">Total Number Of Students {{ students.length }}</td>
              </tr>
            </tfoot>
          </table>
        </div>
      </main>
    </div>

    <footer>
      <p>copyrights © reserved to ITI</p>
    </footer>

    <!-- Add Student Modal Dialog -->
    <div class="modal fade" id="addStudentModal" tabindex="-1" aria-labelledby="addStudentModalLabel" aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <h5 class="modal-title" id="addStudentModalLabel">Add Student</h5>
            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
          </div>
          <div class="modal-body">
            <div class="form-group">
              <label>ID</label>
              <input type="number" v-model="newStudent.id" class="form-control" />
            </div>
            <div class="form-group">
              <label>Name</label>
              <input type="text" v-model="newStudent.name" class="form-control" />
            </div>
            <div class="form-group">
              <label>City</label>
              <input type="text" v-model="newStudent.city" class="form-control" />
            </div>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancel</button>
            <button type="button" class="btn btn-primary" @click="addStudent">OK</button>
          </div>
        </div>
      </div>
    </div>

    <!-- Student Details Modal -->
    <div class="modal fade" id="studentDetailsModal" tabindex="-1" aria-labelledby="studentDetailsModalLabel" aria-hidden="true">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <h5 class="modal-title" id="studentDetailsModalLabel">Student Details</h5>
            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
          </div>
          <div class="modal-body" v-if="selectedStudent">
            <p><strong>ID:</strong> {{ selectedStudent.id }}</p>
            <p><strong>Name:</strong> {{ selectedStudent.name }}</p>
            <p><strong>City:</strong> {{ selectedStudent.city }}</p>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      activeTab: "about",
      showModal: false,
      modal: null,
      showDetailsModal: false,
      selectedStudent: null,
      students: [
        { id: 100, name: "elshaar", city: "meet ghamr" },
        { id: 200, name: "ahmed", city: "cairo" },
        { id: 300, name: "mohamed", city: "alex" },
        { id: 400, name: "moustafa", city: "mahala" },
      ],
      newStudent: {
        id: "",
        name: "",
        city: "",
      },
    };
  },
  methods: {
    openModal() {
      // eslint-disable-next-line no-undef
      this.modal = new bootstrap.Modal(document.getElementById("addStudentModal"));
      this.modal.show();
    },
    addStudent() {
      if (this.newStudent.id && this.newStudent.name && this.newStudent.city) {
        this.students.push({ ...this.newStudent });
        this.closeModal();
      } else {
        alert("Please fill all fields");
      }
    },
    toggleDetails(student) {
      this.selectedStudent = student;
      // eslint-disable-next-line no-undef
      this.modal = new bootstrap.Modal(document.getElementById("studentDetailsModal"));
      this.modal.show();
    },
    closeModal() {
      if (!this.modal) return;
      this.modal.hide();
    },
  },
};
</script>

<style>
* {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}

body {
  font-family: Arial, sans-serif;
}

.container {
  max-width: 1200px;
  margin: 0 auto;
}

header {
  background-color: #fff8dc;
  padding: 20px;
  text-align: center;
}

.content {
  display: flex;
}

.sidebar {
  width: 200px;
  background-color: #f8f9fa;
}

.sidebar ul {
  list-style: none;
}

.sidebar li a {
  display: block;
  padding: 10px 15px;
  text-decoration: none;
  color: #333;
  border-bottom: 1px solid #ddd;
}

.sidebar li a.active {
  background-color: #007bff;
  color: white;
}

.main-content {
  flex: 1;
  padding: 20px;
}

.table-container {
  border: 1px solid #ddd;
}

.table-header {
  padding: 10px;
  background-color: #f8f9fa;
}

.btn-add {
  background-color: #5b9bd5;
  color: white;
  border: none;
  padding: 8px 15px;
  cursor: pointer;
  width: 100%;
}

.students-table {
  width: 100%;
  border-collapse: collapse;
}

.students-table th,
.students-table td {
  border: 1px solid #ddd;
  padding: 8px;
  text-align: left;
}

.students-table th {
  background-color: #5b9bd5;
  color: white;
}

.btn-toggle {
  background-color: #5b9bd5;
  color: white;
  border: none;
  padding: 5px 10px;
  cursor: pointer;
}

footer {
  background-color: #d9edf7;
  padding: 10px;
  text-align: center;
  margin-top: 20px;
}

/* Modal styles */
.modal {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.5);
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 1000;
}

.modal-content {
  background-color: white;
  padding: 20px;
  border-radius: 5px;
  width: 400px;
  position: relative;
}

.modal-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  border-bottom: 1px solid #ddd;
  padding-bottom: 10px;
  margin-bottom: 15px;
}

.close-btn {
  background: none;
  border: none;
  font-size: 24px;
  cursor: pointer;
}

.modal-body {
  margin-bottom: 15px;
}

.modal-footer {
  border-top: 1px solid #ddd;
  padding-top: 15px;
  display: flex;
  justify-content: flex-end;
}

.form-group {
  margin-bottom: 15px;
}

.form-group label {
  display: block;
  margin-bottom: 5px;
  font-weight: bold;
}

.form-group input {
  width: 100%;
  padding: 8px;
  border: 1px solid #ddd;
}

.modal-buttons {
  display: flex;
  justify-content: space-between;
  margin-top: 20px;
}

.btn-ok,
.btn-cancel {
  background-color: #5b9bd5;
  color: white;
  border: none;
  padding: 8px 15px;
  cursor: pointer;
  width: 48%;
}
</style>
