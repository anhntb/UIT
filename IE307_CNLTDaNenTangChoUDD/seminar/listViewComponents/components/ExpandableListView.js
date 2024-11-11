import React, { useState } from 'react';
import { View, Text, TouchableOpacity, FlatList, StyleSheet } from 'react-native';

const ExpandableListView = () => {
  const [expanded, setExpanded] = useState({});

  const toggleExpand = (section) => {
    setExpanded((prev) => ({ ...prev, [section]: !prev[section] }));
  };

  const data = [
    { title: 'Section 1', items: ['Item 1.1', 'Item 1.2'] },
    { title: 'Section 2', items: ['Item 2.1', 'Item 2.2'] },
  ];

  return (
    <FlatList
      data={data}
      keyExtractor={(item) => item.title}
      renderItem={({ item }) => (
        <View>
          <TouchableOpacity onPress={() => toggleExpand(item.title)}>
            <Text style={styles.sectionHeader}>{item.title}</Text>
          </TouchableOpacity>
          {expanded[item.title] &&
            item.items.map((subItem, index) => (
              <Text key={index} style={styles.itemText}>
                {subItem}
              </Text>
            ))}
        </View>
      )}
    />
  );
};

const styles = StyleSheet.create({
  sectionHeader: { fontSize: 18, fontWeight: 'bold', padding: 10},
  itemText: { fontSize: 16, paddingLeft: 20, paddingVertical: 5 },
});
export default ExpandableListView;
