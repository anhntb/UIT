// Show Timeline using React Native Timeline ListView
// https://aboutreact.com/react-native-timeline-listview/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {StyleSheet, Text, View, Image} from 'react-native';

// import Timeline
import Timeline from 'react-native-timeline-flatlist';

const OverrideRenderTimeLine = () => {
  const data = [
    {
      time: '09:00',
      title: 'Event 1',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      lineColor: '#009688',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
    {
      time: '10:45',
      title: 'Event 2',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
    {
      time: '12:00',
      title: 'Event 3',
      icon: require('../img/place_holder.png'),
    },
    {
      time: '14:00',
      title: 'Event 4',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      lineColor: '#009688',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
    {
      time: '16:30',
      title: 'Event 5',
      description:
        'Lorem Ipsum is simply dummy text of the printing.',
      icon: require('../img/place_holder.png'),
      imageUrl:
        'https://images.pexels.com/photos/2250394/pexels-photo-2250394.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=250&w=250',
    },
  ];

  const renderDetail = (rowData, sectionID, rowID) => {
    let title = <Text style={[styles.rowTitle]}>{rowData.title}</Text>;
    var desc = null;
    if (rowData.description && rowData.imageUrl)
      desc = (
        <View style={styles.descriptionContainer}>
          <Image
            source={{uri: rowData.imageUrl}}
            style={styles.imageStyle}
          />
          <Text style={[styles.textDescriptionStyle]}>
            {rowData.description}
          </Text>
        </View>
      );

    return (
      <View style={{flex: 1}}>
        {title}
        {desc}
      </View>
    );
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>
        Override Render TimeLine Example
      </Text>
      <Timeline
        data={data}
        circleSize={20}
        circleColor="rgba(0,0,0,0)"
        lineColor="rgb(45,156,219)"
        timeContainerStyle={{minWidth: 52, marginTop: -5}}
        timeStyle={{
          textAlign: 'center',
          backgroundColor: '#ff9797',
          color: 'white',
          padding: 5,
          borderRadius: 13,
        }}
        descriptionStyle={{color: 'gray'}}
        options={{
          style: {paddingTop: 5},
        }}
        innerCircle={'icon'}
        onEventPress={(item) => 
          alert(`${item.title} at ${item.time}`)
        }
        renderDetail={renderDetail}
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
  rowTitle: {
    fontSize: 16,
    fontWeight: 'bold',
  },
  descriptionContainer: {
    flexDirection: 'row',
    paddingRight: 50,
  },
  imageStyle: {
    width: 50,
    height: 50,
    borderRadius: 25,
  },
  textDescriptionStyle: {
    marginLeft: 10,
    color: 'gray',
  },
});

export default OverrideRenderTimeLine;