<template>
    <div id="app">
      <todo-list v-bind:todos="todos"></todo-list>
    </div>
</template>

<script>
import TodoList from './components/TodoList'

export default {
    name: 'App',
    components: {
        TodoList
    },

    data: function () {
        return {
            todos: [{
                title: 'Todo First',
                project: 'Project A',
                done: false
            }, {
                title: 'Todo Second',
                project: 'Project B',
                done: true
            }, {
                title: 'Todo Third',
                project: 'Project C',
                done: false
            }]
        }
    }
}
</script>

<style>
#yo {
    font-family: 'Avenir', Helvetica, Arial, sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
    text-align: center;
    color: #2c3e50;
    margin-top: 60px;
}
</style>
