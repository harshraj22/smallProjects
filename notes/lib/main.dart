import 'package:flutter/material.dart';
import 'note.dart';

void main() {
  runApp(
    const MaterialApp(
      home: Home(),
    ),
  );
}

class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  List<Note> _cards = [
    Note(title: 'title 1', description: 'description 1'),
    Note(title: 'title 2', description: 'description 2'),
    Note(title: 'title 3', description: 'description 3'),
    Note(title: 'title 4', description: 'description 4'),
    Note(title: 'title 5', description: 'description 5'),
    Note(title: 'title 6', description: 'description 6'),
    Note(title: 'title 7', description: 'description 7'),
    Note(title: 'title 8', description: 'description 8'),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Flutter Demo app'),
      ),
      body: SingleChildScrollView(
        scrollDirection: Axis.vertical,
        child: Wrap(
          children: _cards,
        ),
      ),
    );
  }
}
