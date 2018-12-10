<template>
    <div>
        <h3>Using Vue CLI</h3>
        <h3>{{ msg }}</h3>
    </div>
</template>

<script>
export default {
  name: 'HelloWorld',
  props: {
    msg: String
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  color: green;
}
</style>
