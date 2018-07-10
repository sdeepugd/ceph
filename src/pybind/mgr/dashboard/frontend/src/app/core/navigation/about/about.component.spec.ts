import { HttpClientTestingModule } from '@angular/common/http/testing';
import { ComponentFixture, TestBed } from '@angular/core/testing';

import { BsModalRef } from 'ngx-bootstrap';
import 'rxjs/add/observable/of';
import { Observable } from 'rxjs/Observable';

import { SummaryService } from '../../../shared/services/summary.service';
import { SharedModule } from '../../../shared/shared.module';
import { configureTestBed } from '../../../shared/unit-test-helper';
import { AboutComponent } from './about.component';

class SummaryServiceMock {
  summaryData$ = Observable.of({
    version:
      'ceph version 14.0.0-855-gb8193bb4cd ' +
      '(b8193bb4cda16ccc5b028c3e1df62bc72350a15d) nautilus (dev)'
  });
}

describe('AboutComponent', () => {
  let component: AboutComponent;
  let fixture: ComponentFixture<AboutComponent>;

  configureTestBed({
    imports: [SharedModule, HttpClientTestingModule],
    declarations: [AboutComponent],
    providers: [BsModalRef, { provide: SummaryService, useClass: SummaryServiceMock }]
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(AboutComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  it('should parse version', () => {
    expect(component.versionNumber).toBe('14.0.0-855-gb8193bb4cd');
    expect(component.versionHash).toBe('(b8193bb4cda16ccc5b028c3e1df62bc72350a15d)');
    expect(component.versionName).toBe('nautilus (dev)');
  });
});
