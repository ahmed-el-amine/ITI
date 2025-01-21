import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule, NgForm } from '@angular/forms';
import { RouterLink } from '@angular/router';
import { LoginForm } from '../../interfaces/auth.interface';

@Component({
  selector: 'app-login',
  imports: [CommonModule, FormsModule, RouterLink],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css',
})
export class LoginComponent {
  formData: LoginForm = {
    email: '',
    password: '',
  };

  isSubmitted = false;
  formError: string | null = null;

  onSubmit(form: NgForm) {
    this.isSubmitted = true;
    this.formError = null;

    if (form.valid) {
      console.log('Form submitted successfully', this.formData);
      alert('Login successful!');
    } else {
      this.formError = 'Please fix the errors in the form before submitting.';
      // Highlight all fields with errors
      Object.keys(form.controls).forEach((key) => {
        const control = form.controls[key];
        if (control.invalid) {
          control.markAsTouched();
        }
      });
    }
  }
}
