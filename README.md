# TCP Socket을 활용한 채팅 프로그램

## 프로젝트 주제

- 라즈베리파이로 서버를 구축하여 다중 클라이언트들이 접속 후 실시간 채팅을 할 수 있는 프로그램

## 프로젝트 목적

- 소켓 프로그래밍을 통해 네트워크 환경에서 멀티 클라이언트 간의 통신을 구현하는 방법을 학습하고  서버-클라이언트 모델을 기반으로 한 대화형 시스템의 구조를 이해합니다. 또한 라즈베리파이 환경에서 서버를 구축 후 진행하여 임베디드 시스템에서 네트워크 프로그래밍을 이해하는데 초점을 맞췄습니다.

## 프로젝트 유형

- 개인 프로젝트

## 개발 인원 / 개발 기간

- 개발 인원 : 박경준
- 개발 기간 : 2024-09-18 ~ 2024-10-02

## 기술 스택

- 주요 언어 : C
- 환경 : Linux
- 개발도구 : RaspberryPi 4
- 네트워크 통신 : TCP Socket

## 핵심 기능

**RaspberryPi server**

![123](https://github.com/user-attachments/assets/a7633236-66e3-41d1-b92a-f993b8941c3e)

RaspberryPi connect

![pic2](https://github.com/user-attachments/assets/470781be-8326-4ecc-bb97-9f27fab9d327)

RaspberryPi server 

**실시간 채팅 기능**

- 여러 클라이언트가 접속하여 실시간으로 메시지를 주고받을 수 있습니다.

![%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-10-01_211706](https://github.com/user-attachments/assets/9312a90e-1e7b-4c51-ad90-03ed0ca01a5b)


**개인 메시지 기능**

- 특정 클라이언트에게만 메시지를 전송할 수 있는 기능을 구현하였습니다.

![%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-10-01_211923](https://github.com/user-attachments/assets/85fd9d9a-4908-4e63-8d7e-84525cdb5fb0)

**멀티스레드 기반 클라이언트 처리**

서버는 멀티스레드 방식을 사용하여 다수의 클라이언트를 동시에 처리하는 기능을 구현했습니다. 각 클라이언트 연결이 독립적인 스레드에서 처리되므로 비동기적인 클라이언트 관리가 가능하며 높은 동시성 처리가 요구되는 네트워크 환경에서 성능을 높였습니다.

acceptcli_thread.c 코드 일부

![%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-10-02_145027](https://github.com/user-attachments/assets/c725b555-06de-409f-ad05-3ef0ca94ad4c)


![%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-10-02_145036](https://github.com/user-attachments/assets/bac581bb-602c-4889-b880-bf4fb6c5cf62)


클라이언트가 접속할 때마다 새로운 스레드 생성

![%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2024-10-02_145041](https://github.com/user-attachments/assets/07e8af72-2d1d-4817-9d1c-d2303ca07265)


클라이언트를 독립적으로 관리하고 각 클라이언트는 자신의 스레드를 통해 메세지를 수신