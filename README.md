# TCP/IP Socket을 활용한 서버-클라이언트 채팅 프로그램

## 프로젝트 주제

- Socket과 Thread를 사용하여 구현한 다중 클라이언트 채팅 프로그램입니다. 이 프로젝트는 라즈베리파이에서 서버를 실행하고 우분투 환경에서 클라이언트를 연결하여 실시간 통신을 진행하였습니다.

## 기술 스택

- 주요 언어 : C
- 운영 환경 : 서버 - RaspberryPi, 클라이언트 - Ubuntu
- 네트워킹 : TCP/IP Socket
- 병렬 처리 : POSIX Thread - pthread

## 주요 기능

1. 실시간 메시지 broadcast 전송
2. Thread를 통한 다중 클라이언트 지원
3. Mutex를 사용하여 임계영역 동기화

**RaspberryPi server**


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