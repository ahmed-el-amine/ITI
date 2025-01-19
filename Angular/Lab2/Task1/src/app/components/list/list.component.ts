import { Component } from '@angular/core';
import { CardComponent } from '../card/card.component';

@Component({
  selector: 'app-list',
  imports: [CardComponent],
  templateUrl: './list.component.html',
  styleUrl: './list.component.css',
})
export class ListComponent {
  OriginalUsers = [
    {
      profilePicture: 'https://placehold.co/100x100',
      username: 'john_doe',
      email: 'john.doe@example.com',
      phoneNumber: '+1234567890',
      birthdate: '1990-01-15',
      roleChip: 'admin',
    },
    {
      profilePicture: 'https://placehold.co/100x100',
      username: 'jane_smith',
      email: 'jane.smith@example.com',
      phoneNumber: '+9876543210',
      birthdate: '1985-06-24',
      roleChip: 'user',
    },
    {
      profilePicture: 'https://placehold.co/100x100',
      username: 'sam_brown',
      email: 'sam.brown@example.com',
      phoneNumber: '+1122334455',
      birthdate: '1992-03-12',
      roleChip: 'moderator',
    },
    {
      profilePicture: 'https://placehold.co/100x100',
      username: 'alice_green',
      email: 'alice.green@example.com',
      phoneNumber: '+9988776655',
      birthdate: '1995-11-05',
      roleChip: 'user',
    },
    {
      profilePicture: 'https://placehold.co/100x100',
      username: 'bob_yellow',
      email: 'bob.yellow@example.com',
      phoneNumber: '+3344556677',
      birthdate: '1988-07-19',
      roleChip: 'moderator',
    },
  ];

  users = this.OriginalUsers;
  searchKeyWord: string = '';
  searchOnChange(event: Event) {
    this.searchKeyWord = (event.target as HTMLInputElement).value;
    if (!this.searchKeyWord) this.users = this.OriginalUsers;
    else
      this.users = this.OriginalUsers.filter((user) => {
        if (user.username.includes(this.searchKeyWord)) return true;
        if (user.email.includes(this.searchKeyWord)) return true;
        if (user.phoneNumber.includes(this.searchKeyWord)) return true;
        if (user.birthdate.includes(this.searchKeyWord)) return true;
        return false;
      });
  }
}
