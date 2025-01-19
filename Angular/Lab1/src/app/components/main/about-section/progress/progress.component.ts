import { Component, Input } from '@angular/core';
import { Skill } from '../types';

@Component({
  selector: 'app-progress',
  imports: [],
  templateUrl: './progress.component.html',
  styleUrl: './progress.component.css',
})
export class ProgressComponent {
  @Input() skill?: Skill;
}
