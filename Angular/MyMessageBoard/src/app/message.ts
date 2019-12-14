export class Message {

  name: string;

  content: string;

  date: Date;

  constructor(name: string, content: string) {
    this.name = name;
    this.content = content;
    this.date = new Date();
  }
}
