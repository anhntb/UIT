// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {StyleSheet, Text, View} from 'react-native';

// import Timeline
import Timeline from 'react-native-timeline-flatlist';

const TemplateTimeLine = () => {
  const data = [
    {
      time: '09:00',
      title: 'Archery Training',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
    },
    {
      time: '10:45',
      title: 'Event 2',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
    },
    {
      time: '12:00',
      title: 'Event 3',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
    },
    {
      time: '14:00',
      title: 'Event 4',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
    },
    {
      time: '16:30',
      title: 'Event 5',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
    },
  ];

  //'rgb(45,156,219)'
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Template Timeline Example</Text>
      <Timeline
        data={data}
        //separator={true}
        circleSize={20}
        circleColor="rgba(0,0,0,0)"
        //circleStyle={{borderWidth:1}}
        //dotColor='yellow'
        //lineWidth={2}
        //lineColor='rgb(45,156,219)'
        //timeTextStyle={{color:'green'}}
        //timeContainerStyle={{minWidth: 65}}
        //titleStyle={{color:'green'}}
        //descriptionStyle={{color:'red'}}
        innerCircle={'icon'}
        //iconStyle={{backgroundColor:'white'}}
        //separatorStyle={{backgroundColor: 'green'}}
        //scrollEnabled={false}
        options={{}}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  title: {
    padding: 16,
    fontSize: 20,
    textAlign: 'center',
    fontWeight: 'bold',
  },
});
export default TemplateTimeLine;