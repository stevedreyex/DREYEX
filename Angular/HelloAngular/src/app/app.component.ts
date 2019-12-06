import { Component, PipeTransform } from '@angular/core';

import { stationList } from './station-list.const';

import { Pipe, PipeTransform} from '@angular/core';
import { pipe } from 'rxjs';

export class PowerBoostCalculatorComponent {
  power = 5;
  factor = 1;
}

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  list = stationList;
}

@Pipe({name: 'exponentialStrengh'})
export class ExponentialStrenghPipe implements PipeTransform{
  transform(value: number, exponent: string): number{
    let exp = parseFloat(exponent);
    return Math.pow(value, isNaN(exp) ? 1 : exp );
  }
}
