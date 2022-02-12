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
    Note(
      title: 'title 1',
      description: 'Some fancy description about first title',
    ),
    Note(title: 'title 2', description: 'description 2'),
    Note(title: 'title 3', description: 'description 3'),
    Note(title: 'title 4', description: 'description 4'),
    Note(title: 'title 5', description: 'description 5'),
    Note(title: 'title 6', description: 'description 6'),
    Note(title: 'title 7', description: 'description 7'),
    Note(title: 'title 8', description: 'description 8'),
    Note(title: 'title 9', description: 'description 9'),
    Note(title: 'title 10', description: 'description 10'),
    Note(title: 'title 1', description: 'description 11'),
    Note(title: 'title 2', description: 'description 12'),
    Note(title: 'title 3', description: 'description 13'),
    Note(title: 'title 4', description: 'description 14'),
    Note(title: 'title 5', description: 'description 15'),
    Note(title: 'title 6', description: 'description 16'),
    Note(title: 'title 7', description: 'description 17'),
    Note(title: 'title 8', description: 'description 18'),
    Note(title: 'title 9', description: 'description 19'),
    Note(title: 'title 10', description: 'description 20'),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Flutter Demo app'),
      ),
      body: Scrollbar(
        child: SingleChildScrollView(
          scrollDirection: Axis.vertical,
          child: Wrap(
            children: _cards,
          ),
        ),
      ),
    );
  }
}
