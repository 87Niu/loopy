<template>
    <NavBar />

    <router-view />
</template>

<script>
import NavBar from './components/NavBar.vue'
import "bootstrap/dist/js/bootstrap"
import "bootstrap/dist/css/bootstrap.min.css"
export default {
    name: "App",
    components: {
        NavBar
    },
    setup() {

    }
}

</script>



<style>
body {
    background-image: url("@/assets/images/background.png");
    background-size: cover;
}
</style>
