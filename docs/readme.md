ros_study
================
### Node   
> - 노드는 메시지로 연결되어 있음.
> - 수행하고자 하는 작업에 따라 늘어남
> - 이때 노드사이이 메세지를 토픽/서비스/액션/파라미터 라 함
------------
### Topic
> - 토픽은 단방향 메시지 송수신 방식
> - publisher/subscriber 로 나누어짐 (단방향)
> - publisher가 남긴 메시지를 subscriber가 실행하는 방식으로 구성됨
> - 비동기성과 연속성이 존재함
> - ros 에서 주로 사용됨 (** 위 비동기성과 연속성으로 인해 센서값 전송이나 연속적으로 정보를 주고 받아야 하는 부분에서 사용됨)
------------
### Service
> - 서비스는 동기식 양방향 송/수신 방식
> - request/response 로 나뉘며 request 하는 노드를 Service Client Resonse하는 노드를 Service server라고 한다
> - 이러한 메시지 형태를 주로 srv 메시지라고 함.
-----------
### Action
> - 액션은 비동기식+동기식 양방향 메시지 송/수신 방식 (토픽과 서비스가 합처진 느낌)
> - Goal을 지정하는 Action client와 중간 값을 보여주는 Action feedback 액션 결과를 전송하는 Action Server로 구성됨
> - 요청와 결과를 전달하는 방식은 서비스와같고, 과정을 전달하는 action feedback은 토픽과 같은 방식으로 전달함.(동기/비동기의 구분)
-----------
### Parameter
> - Parameter는 각 node의 Parameter서버를 실행시켜 노드 내부의 매개변수나 글로벌 매개변수를 get/set할 수 있음
