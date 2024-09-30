import 'react-native-gesture-handler';
import { NavigationContainer } 
from '@react-navigation/native';
import { createDrawerNavigator } 
from '@react-navigation/drawer';
import Trangchu from './pages/Trangchu';
import Spage from './pages/Spage';
import Tpage from './pages/Tpage';
const Drawer = createDrawerNavigator();
function App() {
  return (
    <NavigationContainer>
      <Drawer.Navigator>
        <Drawer.Screen
          name="Trangchu"
          options={{drawerLabel: 'Trang Chủ', title: 'Trang Chủ'}}
          component={Trangchu} />
        <Drawer.Screen
          name="SecondPage"
          options={{ drawerLabel: 'Trang Cấu Hình', title: 'Cấu Hình'   }}
          component={Spage} />
           <Drawer.Screen
          name="TdPage"
          options={{   drawerLabel: 'Trang Chi Tiết',    title: 'Chi Tiết'   }}
          component={Tpage} />
      </Drawer.Navigator>
    </NavigationContainer>
  );
}

export default App;