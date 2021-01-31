import 'package:flutter/material.dart';

class Screen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text('Screen page'),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Text(
                'You have pushed the button this too many times:',
              ),
              RaisedButton(
                child: Text('Go Back'),
                onPressed: () {
                Navigator.pop(context);
              }),
            ],
          ),
        ),
      );
  }
}