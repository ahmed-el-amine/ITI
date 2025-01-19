import { Component, CUSTOM_ELEMENTS_SCHEMA } from '@angular/core';
import { NavbarComponent } from './components/navbar/navbar.component';
import { FooterComponent } from './components/footer/footer.component';
import { HeroSectionComponent } from './components/main/hero-section/hero-section.component';
import { AboutSectionComponent } from './components/main/about-section/about-section.component';
import { ProjectSectionComponent } from './components/main/project-section/project-section.component';
import { ContactSectionComponent } from './components/main/contact-section/contact-section.component';

@Component({
  selector: 'app-root',
  imports: [
    NavbarComponent,
    FooterComponent,
    HeroSectionComponent,
    AboutSectionComponent,
    ProjectSectionComponent,
    ContactSectionComponent,
  ],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css',
  schemas: [CUSTOM_ELEMENTS_SCHEMA],
})
export class AppComponent {
  ngAfterViewInit(): void {
    (window as any).initScriptAfterPageLoad();
  }
}
