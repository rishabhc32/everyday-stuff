<template>
    <button v-on:dblclick="increaseCount">You clicked me {{ counter }} times.</button>
</template>

<script>
export default {
    name: 'Button',
    data: () => {
        return {
            counter: 0
        }
    },
    methods: {
        increaseCount: function() {this.counter++}  
    }
}
</script>
