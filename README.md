# Embedded101
## 청주대학교 융합신기술대학원 기계항공산업학과 2021년도 1학기 임베디드시스템 실습자료
------
------
## 0. Pin Layout
- Arduino Nano, Leonardo, Due, Mega2560의 pin layout 정보
- 실습과정 때 활용하는 임베디드보드에 따라 핀 배열상태 확인하고 작업 필요함
------
------
## 1. GPIO 실습
- Single LED와 RGB 3색 LED를 활용한 실습
- 초음파 센서를 연결하여 거리값을 받고 이를 활용하여 적색/녹색 LED 운용하는 실습
- 줌 동영상으로 핀 배열 알아보기 힘든 경우에는 사진을 통해 LED 핀배열 확인 후 적용
- 그 외의 문의는 swcho84@gmail.com 또는 github에 issue 기능으로 문의
------
------
## 2. Serial 실습
- Arduino Due와 Leonardo를 각각 2개의 시리얼 라인으로 연결하여 실습
- 1번 라인: Arduino Leonardo에 연결된 시리얼 모니터에서 문자 입력하면 Arduino Due의 시리얼 모니터에 해당 문자를 출력
- 2번 라인: Arduino Due에 스위치 연결한 다음, 스위치가 on상태이면 'y'문자를 생성하고 이를 Arduino Leonardo로 전송함, 이때, Arduino Leonardo는 전송받은 'y'문자를 활용하여 RGB LED를 녹색으로 셋팅함, 그 외의 경우에는 적색으로 셋팅함
- 줌 동영상으로 핀 배열 알아보기 힘든 경우에는 사진을 통해 LED 핀배열 확인 후 적용
- 그 외의 문의는 swcho84@gmail.com 또는 github에 issue 기능으로 문의
------
------
## 3. I2C 실습
- Arduino Due와 Leonardo를 각각 I2C 통신 실습
- basic: Arduino Due(Master)에서 Arduino Leonardo(Slave)에게 byte data를 요청하고 그 결과를 출력 
- advanced: Arduino Due(Master에서 analog joystic 정보를 입력받아 Arduino Leonardo(Slave)에게 해당 정보를 전달하고 slave에서 그 결과를 출력
- 줌 동영상과 근접 동영상으로 핀 배열 알아보기 힘든 경우에는 사진을 통해 LED 핀배열 확인 후 적용
- 그 외의 문의는 swcho84@gmail.com 또는 github에 issue 기능으로 문의