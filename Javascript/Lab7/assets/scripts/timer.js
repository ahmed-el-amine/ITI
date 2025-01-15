class Timer {
  constructor(element, duration, callbackFunc) {
    this.element = element;
    this.duration = duration;
    this.timerValue = duration;
    this.intervalId = null;
    this.callbackFunc = callbackFunc;
  }

  start() {
    this.element.textContent = this.timerValue;
    this.intervalId = setInterval(() => {
      this.timerValue--;
      this.element.textContent = this.timerValue;

      if (this.timerValue === 0) {
        this.stop();

        this.callbackFunc();
      }
    }, 1000);
  }

  stop() {
    clearInterval(this.intervalId);
  }

  reset() {
    this.timerValue = this.duration;
    this.element.textContent = this.timerValue;
  }
}

export default Timer;
