import {
  Directive,
  ElementRef,
  EventEmitter,
  HostListener,
  Input,
  Output,
  Renderer
} from '@angular/core';

@Directive({
  selector: '[]'
})
export class MyDirectiveComponent {
  @Input() myInputProp: any;
  @Output() myOutputProp = new EventEmitter<any>(); 

  constructor(private elt: ElementRef, renderer: Renderer) {}
  
  @HostListener('mouseenter') onMouseEnter() {
    // Do something...
  }
}
