# Minimun stack

El objetivo es obtener el minimo de un dentro de un stack, teniendo todas las propiedades del stack, las cuales son insertar en el tope y sacar del tope. Puede parecer muy fácil, pero la forma de hacer este problema es utilizando un stack de pair<int, int>

        stack< piar<int, int > > st;

Encontrar el minimo en el stack se va a encontrar en st.top().second.

Añadir elemento:
        int newMin = st.empty() ? newElem : min(newElem, st.top().second);
        st.push({newElem, newMin});

removiendo un elemento:
        int removedElement = st.top().first;
        st.pop();

encontrar el minimo:
        int minimun = st.top().secon;

# Minimun Queue

Ahora vamos a implementar una queue y encontrar el minimo dentro de la queue, hay varias implementaciones pero en este caso vamos a ver la implementación completa de una queue, y para esto vamos a utilizar dos stacks s1, s2.
y vamos a insertar en s1 y cuando tengamos que sacar el elemento del frente vamos a sacarlo del s2, pero en que momento vamos a pasar a pasar los elementos del stack s1 a s2?. Lo vamos a hacer cuando se vaya a sacar el elemento del frente y el stack s2 este vacia. y de esa forma vamos a tener una simulación perfecta de una queue.

encontrar el minimo:
        if(s1.empty() || s2.empty())
                minimun = s1.empty() ?  s2.top().second : s1.top().second;
        else 
                minimun = min( s1.top().second, s2.top().second );

añadiendo elemento:

        int minimum = s1.empty() ? newElem : min( newElem, s1.top().second )
        s1.push( { newElem, minimu} );

Removiendo un elemento:

        if(s2.empty()) {
                while(!s1.empty()) {
                        int element = s1.top().first;
                        s1.pop();
                        int minimun = s2.empty() ? element : min( element, s2.top().second);
                        s2.push( { element, minimum});
                }
        }
        int removeElem = s2.top().first;
        s2.pop();