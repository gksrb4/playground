import 'dart:async';
import 'dart:io';
import 'dart:isolate';

Isolate isolate;

main() {
  print("running dart program");
  createNewIsolate(10);
  print("after main");
}

void createNewIsolate(int cnt) {
  final data = List.generate(cnt, (index) => index);
  ReceivePort receivePort = ReceivePort();
  Isolate.spawn(isolateMain, {"sendPort": receivePort.sendPort, "data": data})
  .then((_isolate) {
    isolate = _isolate;
    print('isolate: $isolate');
    receivePort.listen((messages) {
      print('new message from ISOLATE $messages');
    });
  });
}

Future<void> _testSendFunc(List<int> data) async {
  await Future.delayed(Duration(seconds: 1));
}

Future<void> isolateMain(Map<String, dynamic> kwargs) async {
  final SendPort sendPort = kwargs["sendPort"];
  final List<int> data = kwargs["data"];

  print('isolate main: $sendPort, $data');
  for (int i=0;i<data.length;i++) {
    print('start $i send');
    await _testSendFunc(data);
    print('end $i send');
    sendPort.send('send $i');
  }
  exit(0);
}
