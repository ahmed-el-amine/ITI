import { Component } from '@angular/core';
import { Skill } from './types';
import { ProgressComponent } from './progress/progress.component';

@Component({
  selector: 'app-about-section',
  imports: [ProgressComponent],
  templateUrl: './about-section.component.html',
  styleUrl: './about-section.component.css',
})
export class AboutSectionComponent {
  skills: Skill[] = [
    { name: 'Web Design', percentage: 100, color: '#c7b1dd' },
    { name: 'Mobile Design', percentage: 80, color: '#8caeec' },
    { name: 'Development', percentage: 85, color: '#b0d4c1' },
  ];
}
